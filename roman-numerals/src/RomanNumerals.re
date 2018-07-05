let rules: array((string, int)) = [|
  ("M", 1000), ("CM", 900),
  ("D", 500), ("CD", 400),
  ("C", 100), ("XC", 90),
  ("L", 50), ("XL", 40),
  ("X", 10), ("IX", 9),
  ("V", 5), ("IV", 4),
  ("I", 1)
|]

let rec toRoman (n: int): string {
  switch(Js.Array.find(((_, value)) => n >= value, rules)) {
  | Some((roman_string, value)) => roman_string ++ toRoman(n - value)
  | None => ""
  }
}