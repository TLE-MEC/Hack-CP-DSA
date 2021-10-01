/*Here Case and Else works as If and Else*/
Select 
    Case 
        When P IS NULL Then CONCAT(N, ' Root')
        When N IN (Select Distinct P from BST) Then CONCAT(N,' Inner')
        Else CONCAT(N,' Leaf')
    END
    from BST
Order By N ASC;