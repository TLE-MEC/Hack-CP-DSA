# working 
# this problem can be easily solved by calculating the number of distinct element in the arr (exlcuding zero)
# we get input (Arr in type <list>) from the main driver code

# eg: 1 1 5 6 8 6 4
# we use set function on our list that outputs only distinct elements from the list (including zeros)
# here distinct elements are 1 5 6 8 4
# we check if a tree with zero length exists or not, if so we delete it 
# then the number of cutting operation required to be done will be equal to the length of the arr left with us

# for the case 1 4 5 6 8   length of the arr is 5
    #step1: we set the cutter at level 6 and cut all the trees having length more than 6 
    #       by which we get 1 4 5 6 6   [8 --> 6]
    
    # updated arr 1 4 5 6 6 that is same as 1 4 5 6
    #step2: we set the cutter at level 5 and perform the same operation resulting in 1 4 5 5 ie same as 1 4 5
    #step3: we set the cutter at level 4 and perform the same operation resulting in 1 4 4 ie same as 1 4
    #step4: we set the cutter at level 1 and perform the same operation resulting in 1 1 ie same as 1
    #step5: Lastly, we set the cutter at level 0 and perform the same operation thus completing the purpose 
# total number of operations needed to be performed are 5 that is equal to the legth of the arr 


def DCTrees(arr):
    arr = list(set(arr))
    if arr.count(0) != 0:
        arr.remove(0)

    return len(arr)


# driver code
# this code takes number of trees and height of all trees as input in <int> and <list> type respectively 
# this data is then passed to a Function called DCTrees()
# we will consider 1 1 5 6 8 6 4 for expanation purpose

if __name__ == '__main__':
    for _ in range(int(input())):
        q = int(input())
        Arr = list(map(int, input().strip().split()))

        print(DCTrees(Arr))
