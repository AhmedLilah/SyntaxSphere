# package require Tk

set current ""
set Ans ""

proc deleteChar {} {
    global current
    set current [string range $current 0 end-1]
}

grid [label  .input -textvariable current -background white] -row 1 -column 1 -sticky ew
grid [label  .result -textvariable Ans -background white] -row 2 -column 1 -sticky ew

grid [frame  .buttons] -row 3 -column 1

button .buttons.button0 -text "0" -command {set current [append current 0]} -width 10 -height 3
button .buttons.button1 -text "1" -command {set current [append current 1]} -width 10 -height 3
button .buttons.button2 -text "2" -command {set current [append current 2]} -width 10 -height 3
button .buttons.button3 -text "3" -command {set current [append current 3]} -width 10 -height 3
button .buttons.button4 -text "4" -command {set current [append current 4]} -width 10 -height 3
button .buttons.button5 -text "5" -command {set current [append current 5]} -width 10 -height 3
button .buttons.button6 -text "6" -command {set current [append current 6]} -width 10 -height 3
button .buttons.button7 -text "7" -command {set current [append current 7]} -width 10 -height 3
button .buttons.button8 -text "8" -command {set current [append current 8]} -width 10 -height 3
button .buttons.button9 -text "9" -command {set current [append current 9]} -width 10 -height 3

button .buttons.buttonDot -text "." -command {set current [append current {.}]} -width 10 -height 3

button .buttons.button+ -text "+" -command {set current [append current +]} -width 10 -height 3
button .buttons.button- -text "-" -command {set current [append current -]} -width 10 -height 3
button .buttons.button* -text "*" -command {set current [append current *]} -width 10 -height 3
button .buttons.button/ -text "/" -command {set current [append current /]} -width 10 -height 3
button .buttons.button^ -text "^" -command {set current [append current **]} -width 10 -height 3

button .buttons.button( -text "(" -command {set current [append current (]} -width 10 -height 3
button .buttons.button) -text ")" -command {set current [append current )]} -width 10 -height 3

button .buttons.button= -text "=" -command {set Ans [expr $current]; set current ""; puts -nonewline $Ans; flush stdout} -width 10 -height 3

button .buttons.buttonAns -text "Ans" -command {set current [append current $Ans]} -width 10 -height 3
button .buttons.buttonC -text "C" -command {set current ""} -width 10 -height 3
button .buttons.buttonD -text "D" -command {eval deleteChar} -width 10 -height 3

grid .buttons.buttonC .buttons.buttonD .buttons.buttonC .buttons.buttonC  -sticky ew
grid .buttons.button( .buttons.button) .buttons.button^ .buttons.button+  -sticky ew
grid .buttons.button7 .buttons.button8 .buttons.button9 .buttons.button-  -sticky ew
grid .buttons.button4 .buttons.button5 .buttons.button6 .buttons.button*  -sticky ew
grid .buttons.button1 .buttons.button2 .buttons.button3 .buttons.button/  -sticky ew
grid .buttons.buttonAns .buttons.button0 .buttons.buttonDot .buttons.button=  -sticky ew
