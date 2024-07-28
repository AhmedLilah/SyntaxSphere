####################################################################################################
##  In TCL everything is a string.
##  The basic tcl programming sentence is like a command line command
##      cmd arg1 arg2 ..
puts {Hello, World!} 


####################################################################################################
##  this is a comment.
##  comments in TCL starts with the # symbol and it can be at the begining or end of the line.

##  the end of a statement in TCL is defined by the end of the line or by a ';'
puts {I'm here.}; # print "I'm here." to the standard output.


####################################################################################################
##  be carefull to use a ';' to end the statement before using the # symbol to make a comment as it could be considered an argument to the command.
##      puts comment # is not a comment => error
puts comment; # is a comment 


####################################################################################################
##  anything between [] is considered a nested command in it's self.
##  we use a '$' before the variable name to access it's value inplace.
set x 50
set y 60
set z [expr $x + $y] 


####################################################################################################
##  set is used to declare and assign a variable if it's not declared befor otherwize is reassignes to it.
set integer1  20
set integer2  20


##  variable names can be a white space seperated string.
set {my variable anme} {50};

##  variable names can start with a special characters. 
set !*str# {!*str# is an unfamiliar variable name}

puts ${my variable anme}
puts ${!*str#}

##  variables can be and alias to others
set expression expr; # makes expression an alias to expr
set sum [$expression $integer1 + $integer2]

##  set implicitly returns the value of the variable.
puts [set name Ahmed]; # prints "Ahmed" to the standard output.

## using the set without a second argument only returns the value of variable.
puts [set name]


####################################################################################################
##  there are to types string delimiters in TCL.
##  the first is the curly brackets "{}" aka the grouping brackets.
##      this treates anything between it as a string including the white spaces.
set gStr {Hello, World!\n$integer1 + $integer2 = [expr $integer1 + $integer2]}
# this creates string that holds what's inside the brackets as is. 

##  the other is the double quotes'""'.
##      this defines an excaped string.
##              C-like string excape characters.
##              Varialbe formmatting using the '$' symbol.
set fStr "Hello, World!\n$integer1 + $integer2 = [expr $integer1 + $integer2]" 
##  this creates this string that is formatted as follows
##      Hello, World!
##      20 + 20 = 40
 

####################################################################################################
##  puts prints the argument to the standard output by.
##  puts implicitly starts  new line after it prints to the output
puts $z

##  we can also explicitly choos the output to which puts writes.
##      puts <ouput> <arg>
puts stdout fStr; # prints to the standard output => is is the default output.
puts stderr gStr; # prints to teh standard error.


####################################################################################################
##  conditions 
####################################################################################################
####################################################################################################
##  to define and procedure (i.e. c like function) use the following syntax:
##  proc <name> {<arg1> <argn>} {body} 
proc pow {base power} {
	set result 1
	## the while loop structure is while {condition} {body}
	while {$power > 0} {
		set result [expr $result * $base]
		set power [expr $power - 1]
	}
	## return returns a value to caller of the procedure.
	return $result
}


