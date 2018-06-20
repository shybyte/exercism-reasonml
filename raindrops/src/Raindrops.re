let factorRaindropPairs= [|
    (3, "Pling"),
    (5, "Plang"),
    (7, "Plong"),
  |]

let raindrops = (x) => {
  let drops = factorRaindropPairs 
    |> Array.map(((factor, drop)) =>(x mod factor === 0) ? drop : "" )
    |> Js.Array.joinWith("");
  
  drops == "" ? string_of_int(x) : drops
}