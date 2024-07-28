var message = "Hello, World!";
console.log(message);
var arr = ["Ahmed", "Sabry", "Ali", "Ali", "Lilah"];
console.log(message.substring(0, 5));
for (var _i = 0, message_1 = message; _i < message_1.length; _i++) {
    var char = message_1[_i];
    console.log(char);
}
for (var index in arr) {
    console.log(index + ": " + arr[index]);
}
