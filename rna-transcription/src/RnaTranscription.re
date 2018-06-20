type dnaNucleotide = G | C | A | T
type rnaNucleotide = G | C | A | U 

let toRnaNucleotide = (dnaNuc: dnaNucleotide) => 
  switch dnaNuc {
    | G => C
    | C => G
    | T => A
    | A => U
  }

let toRna = List.map(toRnaNucleotide)