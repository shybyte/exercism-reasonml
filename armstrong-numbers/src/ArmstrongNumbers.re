open Js.String
open Js.Math
open Array

let sum(xs): int = fold_right((s, x) => s + x, xs, 0);

let validate(x: int) = {
  let digits = x |> string_of_int |> split("") |> map(int_of_string);
  sum(map(d => pow_int(d, length(digits)) , digits)) == x
};
