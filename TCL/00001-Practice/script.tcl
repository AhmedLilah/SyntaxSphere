# #!
# proc factorial {a} {
#         if {$a == 1 || $a == 0} {
#                 return 1;
#         }
#         return [expr $a * [factorial [expr $a-1]]];
# }

# for {set i 10} {$i > -1} {incr i -1} {
#         puts [factorial $i];
# }


# proc Foreach {element list expr} {
#         for {set index 0} {$index < [llength $list]} {incr index} {
#                 set $element [lindex $list $index];
#                 eval $expr;
#         }
# }


# set myList {AHMED LILAH};

# Foreach x $myList {
#         puts $x;
# }

# set openFileError [catch {
#                 set file [open "script.tcl" r+]
#         }
# ]

# # if {$openFileError} {
# #         puts "ErrorMsg  : $result";
# #         puts "ErrorCode : $errorCode";
# #         puts "ErrorInfo : $errorInfo";
# # } else {
# #         puts [read $file];
# #         set Time [clock seconds]
# #         puts "\[File-Modified\]: [clock format $Time -format {%A %d-%m-%Y %r %Z}]"
# # }

# proc printf {fStr args} {
#         puts [format $fStr [string split $args " "]]
# }

# printf "%d %u" 10 10

set i 0

proc For {count body {index 0}} {
        if {$count > $index} {
                eval $body
                incr index
                For $count $body $index
        }
}

while {$i < 5} {
        puts $i
        incr i
}

For {5} {
        puts $index
}
