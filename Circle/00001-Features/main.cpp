#feature on as no_implicit_integral_narrowing no_implicit_floating_narrowing 
#feature on forward
#feature on simpler_precedence 
#feature on new_decl_syntax
#feature on choice

#include <iostream>

fn func(str : std::string) -> int {
	std::cout << str << '\n';
}

choice Cards {
	King(int),
	Jack(double),
	Queen(char),
	Function(func), 
	Winner,
}; 

fn matchCard(card : Cards) {
	match (card) {
		.King(int)	=> "King";
		.Jack(double) 	=> "Jack";
		.Queen(char)	=> "Queen";
		.Winner		=> "Winner";
		.Function(func)	=> .Function(std::string("func"));
		_ 		=> "";
	};
}


fn main() -> int {
	var card : Cards = .Function(func);
	matchCard(card);
	return 0;
}
