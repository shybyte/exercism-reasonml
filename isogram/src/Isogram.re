open Js.String;
open Belt;

let is_isogram(s) = {
  let letters =  s
    |> toLowerCase
    |> replaceByRe([%re "/[ -]/g"], "")
    |> split("");
  Array.length(letters) === Set.String.size(Set.String.fromArray(letters))
}
