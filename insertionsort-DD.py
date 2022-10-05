'''
name1: AJ1 Fahim1
name2: AJ2 Fahim2

assignment:PA2
'''
import sys
import random
import time

class Solution:
	
	#This function returns a descending sorted array.
	def function_a (self, elements_count: int) -> list:
		output = []
		for i in range(elements_count,0, -1):
			output.append(i)
		return output

	#This function returns an ascending sorted array.	
	def function_b (self, elements_count: int) -> list:
		output = []
		for i in range(1, elements_count):
			output.append(i)
		return output

	def function_c(self, elements_count: int, seed: int):
		output = []
		random.seed(seed)
		for i in range(0,elements_count+1):
			output.append(random.randint(1,1000000))

		return output


	def select_input(self, input_type: str, elements_count: int, seed: int) -> list:
		output = []
		if input_type == "a":
			output = self.function_a(elements_count)
		if 	input_type == "b":
			output = self.function_b(elements_count)
		if 	input_type == "c":
			output = self.function_c(elements_count, seed)
		return output	

	def pa2_insertionsort (self, input_type: str, elements_count: int, seed: int) -> list:
		output = []
		query_list = self.select_input(input_type, elements_count, seed)
		
		n = len(query_list)

		# get the start time
		st = time.process_time()
		
    	# your insertion sort algorithm comes here ...

		for j in range(1,len(query_list)):
			# sorts the input members in place: rearranges the numbers within the array A 
			# j indicates the current element being inserted into the array 
			# start j at the second element in the array at index 1
			key = query_list[j]
			# key holds the value of A[j] for the following comparisons 
			# Insert A[j] into the sorted sequence A[1..j-1]
			# compare key with the value to its left at index i 
			i = j - 1
			while i >= 0 and query_list[i] > key:
				# if A[i] is greater than key, then move A[i] one position to the right
				query_list[i+1]= query_list[i]
				i -= 1 # decrement i by 1
			query_list[i + 1] = key # move key one position to the right

    	# end of insertion sort
		
		et = time.process_time()
		res = et - st

		return [query_list, res]




if __name__ == '__main__':
	input_type = sys.argv[1]
	elements_count = int(sys.argv[2])
	seed = sys.argv[3]
	
	obj = Solution()
	ret = obj.pa2_insertionsort(input_type, elements_count, seed)
	print(ret)

