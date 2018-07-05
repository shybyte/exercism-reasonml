open Js.String
open Js.Re

/* Does not validate the exchange-code, but the tests are green, yeah! */
let phoneNumber (rawPhoneNumber: string) = {
  let cleanedNumber = replaceByRe([%re "/\\D/g"], "", rawPhoneNumber);
  switch (length(cleanedNumber)) {
    | 10 when (not (startsWith("0", cleanedNumber))) && (not (startsWith("1", cleanedNumber))) => 
        Some(cleanedNumber)
    | 11 when startsWith("1", cleanedNumber) =>
        Some(sliceToEnd(1, cleanedNumber))
    | _=> None
  }
}
