#optimization->1
#25/5/26



#For this problem, I want you to write a function called interleave which accepts two iterables
#of any type and return a new iterable with each of the given items "interleaved" 
#(item 0 from iterable 1, then item 0 from iterable 2, then item 1 from iterable 1, and so on).

#We are making an assumption here that both iterables contain the same number of elements.

##solution-----------------------------------------------------------------------------------------------

def interleave(iter1,iter2):
    
        new_list=[]
        i=0
        n=len(iter1)        #wasted line 

        for x in iter1:
            new_list.append(x)
            new_list.append(iter2[i])
            i +=1
        return new_list



#this is the pure pythonic code by ai

def interleave(*iterables):
    new_list = []
    
    # zip(*iterables) creates tuples like (1, 4, 7), then (2, 5, 8)...
    for group in zip(*iterables):
        # .extend() adds all items from the tuple into our flat list
        new_list.extend(group)
        
    return new_list

print(interleave([1, 2, 3], [4, 5, 6], [7, 8, 9]))
# Output: [1, 4, 7, 2, 5, 8, 3, 6, 9]
    