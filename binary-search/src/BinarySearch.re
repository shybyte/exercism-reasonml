let find (array, value) = {
  let rec find' (range_start: int, range_end: int) = {
    if (range_start >= range_end) {
      None
    }
    else if (range_start == range_end - 1) {
      if (array[range_start] == value) {
        Some(range_start)
      } else {
        None
      }
    } else  {
      let middleIndex = range_start + ((range_end - range_start) / 2);
      if (value < array[middleIndex]) {
        find'(range_start, middleIndex)
      } else {
        find'(middleIndex, range_end)
      }
    }
  };
  
  find'(0, Array.length (array))
}
