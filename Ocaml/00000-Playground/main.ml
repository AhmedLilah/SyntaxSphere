open Printf;;

let rec fac a = 
        if a = 0 then 0
        else if a = 1 then 1
        else fac (a - 1) + fac (a -2);;

print_endline "Enter the number that you want the factorial of: ";;

let x = read_line();;

print_endline ("!" ^ x ^ " = " ^ string_of_int  (fac (int_of_string x)));;

let rec length u =
        match u with
        | [] -> 0
        | _ :: v -> 1 + length v;;

let range = [0; 1; 2; 3; 4; 5];;

let () = List.iter (printf "%d ") range;;

print_endline (string_of_int (length range));;
