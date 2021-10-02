<?php

// Complete the sockMerchant function below.
function sockMerchant($n, $ar) {
    $arr=$ar;
  $unique=array_unique($ar);
  $con=0;
  $values=array_values($unique);
  for($counter=0;$counter<count($values);$counter++)
  {
     $pair=0;
      $i=0;
      while($i<count($arr))
      {
          if($values[$counter]==$arr[$i])
          {
              $pair++;
              echo $pair; 
          }
          $i++;
      }
      if($pair%2==0)
      {
          $con+=$pair/2;
      }
      else
      {
          $con+=($pair-1)/2;
      }
  }
  return $con;
  
    
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $n);

fscanf($stdin, "%[^\n]", $ar_temp);

$ar = array_map('intval', preg_split('/ /', $ar_temp, -1, PREG_SPLIT_NO_EMPTY));

$result = sockMerchant($n, $ar);

fwrite($fptr, $result . "\n");

fclose($stdin);
fclose($fptr);
