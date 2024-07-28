let message : string = "Hello, World!";
console.log(message);

let arr : Array<string> = ["Ahmed", "Sabry", "Ali", "Ali", "Lilah"];
console.log(message.substring(0,5));

for (var char of message) {
        console.log(char);
}

for (var index in arr) {
        console.log(index + ": " + arr[index]);
}

// 👇️ const input: HTMLInputElement | null
const input = document.getElementById('message') as HTMLInputElement | null;

const value = input?.value;
console.log(value) // 👉️ "Initial value"

if (input != null) {
  console.log(input.value); // 👉️ "Initial value"
}

input?.addEventListener('input', function (event) {
  const target = event.target as HTMLInputElement;
  console.log(target.value);
});
