open Js.String

let encode (s: string) = {
  let replaceFn (matchPart, char,  _,  _) = string_of_int(length(matchPart)) ++ char;
  unsafeReplaceBy1([%re "/(.)\\1+/g"], replaceFn, s)
}

let decode (s: string) = {
  let replaceFn (_, count, char,  _,  _) = repeat(int_of_string(count), char);
  unsafeReplaceBy2([%re "/(\\d+)(.)/g"], replaceFn, s)
}

