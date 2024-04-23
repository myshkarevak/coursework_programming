#!/bin/bash

[ -d app ] || mkdir app
if [ ! -x app/app ]; then
    echo "app not found, starting compilation"
    bash scripts/build.sh
fi

continueEvaluation=true

WX_MAXIMA_CALCULATION_ITEM=("WXMaxima calculation" "wxmaxima scripts/calculation.wxmx")
C_LANG_CALCULATION_ITEM=("C_LANG calculation" "./app/app")
WX_MAXIMA_PLOTS_ITEM=("Draw plots" "wxmaxima scripts/plots.wxm")
EXIT_ITEM=("Exit" "((continueEvaluation=false))")

MENU_ITEMS=(
    WX_MAXIMA_CALCULATION_ITEM[@]
    C_LANG_CALCULATION_ITEM[@]
    WX_MAXIMA_PLOTS_ITEM[@]
    EXIT_ITEM[@]
)

MENU_SIZE=${#MENU_ITEMS[@]}
LAST_ACTIVE_INDEX=$((MENU_SIZE - 1))
FIRST_ACTIVE_INDEX=0
ENTER_KEY=$'\0A'
ARROW_UP_KEY=$'\x1b[A'
ARROW_DOWN_KEY=$'\x1b[B'

getPressedKeyCode() {
    read -rsn3 key
    printf "%s" "$key"
}

drawArrowMenu() {
    clear
    echo "Use ARROW_UP and ARROW_DOWN to navigate,"
    echo "ENTER to confirm"
    echo
    for ((i = 0; i < MENU_SIZE; i++)); do
        if [ "$currentMenuItemIndex" = "$i" ]; then
            echo "-> ${!MENU_ITEMS[i]:0:1}"
        else
            echo "   ${!MENU_ITEMS[i]:0:1}"
        fi
    done
}

arrowMenuHandler() {
    currentMenuItemIndex=$FIRST_ACTIVE_INDEX
    while $continueEvaluation; do
        drawArrowMenu
        pressedKey=$(getPressedKeyCode)
        case $pressedKey in
            $ARROW_DOWN_KEY)
                ((currentMenuItemIndex++))
                if [ $currentMenuItemIndex -gt $LAST_ACTIVE_INDEX ]; then
                    currentMenuItemIndex=$FIRST_ACTIVE_INDEX
                fi;;
            $ARROW_UP_KEY)
                ((currentMenuItemIndex--))
                if [ $currentMenuItemIndex -lt $FIRST_ACTIVE_INDEX ]; then
                    currentMenuItemIndex=$LAST_ACTIVE_INDEX
                fi;;
            $ENTER_KEY)
                eval "${!MENU_ITEMS[$currentMenuItemIndex]:1:1}";;
        esac
    done
    clear
}

arrowMenuHandler