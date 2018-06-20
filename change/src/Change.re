/* Based on  https://www.youtube.com/watch?v=rdI94aW6IWw */

let maxValue = 1000_000_000;

let findMin = (array: array(int), getWeight: (int) => int): (int, int) => {
  let minIndex = ref(None);
  let minWeight = ref(maxValue);

  Array.iteri((i, v) => {
    let weight = getWeight(v);
    if (weight < minWeight^) {
      minIndex := Some(i);
      minWeight := weight;
    }
  }, array);

  switch minIndex^ {
  | Some(minIndex') => (minWeight^, array[minIndex'])
  | None => (maxValue, 0)
  }
}

let makeChangeInternal = (changeValue: int, coins: array(int)) => {
  let c = [|0|];
  let s = [|0|];

  for (x in 1 to (changeValue)) {
    let (minCost, minCoin) = findMin(coins, (coin: int): int =>
      ((coin <= x) ? c[x - coin] + 1 : maxValue)
    );
    Js.Array.push(minCost, c) |>ignore;
    Js.Array.push(minCoin, s) |>ignore;
  };

  if (c[changeValue] < maxValue) {
    let result = ref([]);
    let i = ref(changeValue);
    while (i^ > 0) {
      result := result^ @ [s[i^]]; 
      i := i^ - s[i^]
    };
    Some(result^)
  } else {
    None
  }
}

let makeChange = (changeValue, coins: list(int)) => {
  if (changeValue >= 0) {
    makeChangeInternal(changeValue, Array.of_list(coins))
  } else {
    None
  }
}

