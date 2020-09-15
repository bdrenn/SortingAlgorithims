-- Haskell Quick Sort

-- Input: list, Output: list 
qsort :: (Ord a) => [a] -> [a] 
-- If the list is empty, return the empty list
qsort [] = []
{-|
  - smaller (list): All elements in xs(tail), that are less than x(head).
  - bigger (list): All elements in xs(tail), that are greater than x(head).
  - Perform the list comprehensions and concatenate the lists together around the pivot (x)
-}
qsort (x:xs) = 
    let smaller = qsort [a | a <- xs, a <= x]
        bigger = qsort [a | a <- xs, a > x]
    in smaller ++ [x] ++ bigger
