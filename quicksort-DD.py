'''
name1: AJ1 Fahim1
name2: AJ2 Fahim2

assignment:PA2
'''
# from curses.ascii import SO
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

	def pa2_quicksort (self, input_type: str, elements_count: int, seed: int) -> list:
		output = []
		query_list = self.select_input(input_type, elements_count, seed)
		
		n = len(query_list)

		# get the start time
		st = time.process_time()
		
    	# your quicksort algorithm comes here ...
		Solution().quicksort(query_list,0,n)

    	# end of quicksort
		
		et = time.process_time()
		res = et - st

		return [query_list, res]

	def quicksort(self, A: list, p: int, r: int):
		if p < r:
			q = Solution().partition(A,p,r)
			Solution().quicksort(A,p,q-1)
			Solution().quicksort(A,q+1,r)
		return 
	
	def partition(self, A: list, p: int, r: int) -> int:
		x = A[r-1]
		i = p - 1
		for j in range(p,r):
			if A[j] <= x:
				i += 1
				A[i], A[j] = A[j], A[i]
		A[i+1], A[r-1] = A[r-1], A[i+1]
		return i + 1




if __name__ == '__main__':
	input_type = sys.argv[1]
	elements_count = int(sys.argv[2])
	seed = sys.argv[3]
	
	obj = Solution()
	ret = obj.pa2_quicksort(input_type, elements_count, seed)
	print(ret)

