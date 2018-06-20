open String;

let isUpperCaseAndHasAlphabeticChars = (s: string) =>
   uppercase(s) === s && s !== lowercase(s)
let isShouting = isUpperCaseAndHasAlphabeticChars
let isQuestion = (s: string) => get(s, length(s)-1) == '?'

let hey = (inputRaw: string) => {
  let input = trim(inputRaw);
  if (length(input) == 0) {
    "Fine. Be that way!"
  } else if (isQuestion(input))    {
    if (isShouting(input)) {
      "Calm down, I know what I'm doing!"
    } else {
      "Sure."
    }
  } else if (isShouting(input)) {
    "Whoa, chill out!"
  } else {
    "Whatever."
  }
}