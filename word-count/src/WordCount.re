open Js.String;

let getValueOrDefault = (dict, key, default) =>
  switch (Js.Dict.get(dict, key)) {
    | Some(value) => value
    | None => default
}

let wordCount = (text: string) => {
  let words =  text
    |> toLowerCase
    |> replaceByRe([%re "/[^'a-zA-Z0-9]+/g"], " ")
    |> trim
    |> splitByRe([%re "/'?\\s+'?/"]);
  
  let dict = Js.Dict.empty();
  Js.Array.forEach((word) => {
    Js.Dict.set(dict, word, getValueOrDefault(dict, word, 0) + 1);
  }, words);

  Js.Dict.entries(dict)
}