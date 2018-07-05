open Belt;
open Js.String;

let alphabetSize = 26

let isPangram = (text: string) => {
  let charSet =  text
    |> toLowerCase
    |> replaceByRe([%re "/[^a-z]/g"], "")
    |> split("")
    |> Set.String.fromArray;
  Set.String.size(charSet) == alphabetSize
}
