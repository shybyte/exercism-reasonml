let isLeapYear = (year: int) => {
  let isDivisibleBy = (x) => year mod x == 0;
  (isDivisibleBy(4) && !isDivisibleBy(100)) || isDivisibleBy(400)
}