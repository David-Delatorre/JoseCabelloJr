'''
name1: AJ1 Fahim1
name2: AJ2 Fahim2

assignment:PA2
'''
from math import floor, inf
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

	def pa2_mergesort (self, input_type: str, elements_count: int, seed: int) -> list:
		output = []
		query_list = self.select_input(input_type, elements_count, seed)
		print(query_list)
		n = len(query_list)

		# get the start time
		st = time.process_time()
		
    	# your merge sort algorithm comes here ...
		Solution().mergesort(query_list,0,n)
    	# end of merge sort
		
		et = time.process_time()
		res = et - st

		return [query_list, res]

	def merge(self, A: list, p: int, q: int, r: int):
		# A is an array and p, q, and r are indices of the array such that p <= q < r 
		# list sliceing simplifies code on lines 1 - 7 of merge pseudocode on pg 31 of CLRS
		# create "left" and "right" arrays L and R of lengths n1 and n2 respectively
		L = list(A[p:q+1])
		# copies the sub-array A[p..q] into L[1..n1] where n1 = q + 1 - p
		R = list(A[q+1:r+1])
		# copies the sub-array A[q+1..r] into L[1..n2] where n2 = r - q
		i, j = 0, 0
		# initialize indexes of L and R lists 
		L.append(inf)
		R.append(inf)
		# the extra position in each array will hold the sentinel
		# we can represent infinity using python's math module
		print("left array: ", L)
		print("right array: ", R)
		for k in range(p,r+1):
			print("p:",p, "r:",r)
			print("k:", k)
			if L[i] == inf and R[j] == inf:
				# if both sub-arrays are indexed at their sentinels , 
				# all of the non-sentinel values have been copied back into A and we are done
				break
			else:
				if L[i] <= R[j]: 
					# L[i] is the smallest elemnt not yet copied back into A
					print(f"L[{i}]= {L[i]} <= R[{j}]= {R[j]}")
					A[k] = L[i] # copy L[i] back into A
					i = i + 1 # increment index of L by 1
				else: # R[j] is the smallest elemnt not yet copied back into A
					print(f"L[{i}]= {L[i]} > R[{j}]= {R[j]}")
					A[k] = R[j] # copy R[j] back into A
					j = j + 1 # increment index of R by 1
				
		print("sorted array:", A)
		return 


	def mergesort(self, A: list, p: int, r: int):
		"""""
		#A is a sub-array with starting index at p and ending index at r -> A[p..r]
		#To sort an entire sequence A = <A[1],A[2]...A[n]>, make the initial call 
		mergesort(A,0,A.length) where A.length = n
		"""
		# if p >= r, the subarray has at most one element and is thus already sorted
		if p < r:
			# otherwise, compute index q that partitions A[p..r] into two subarrays
			# A[p..q] contains ceiling(n/2) elements
			# A[q+1..r] contains floor(n/2) elements
			print(f"start {p} < end {r}")
			q = floor((p+r)/2)
			print("middle: ", q)
			print(f"sort sub-array from {p} to {q}")
			Solution().mergesort(A,p,q)
			print(f"sort sub-array from {q+1} to {r}")
			Solution().mergesort(A,q+1,r)
			print(f"merge two sub-arrays start {p} middle {q} end {r}")
			Solution().merge(A,p,q,r)
		return


if __name__ == '__main__':
	input_type = sys.argv[1]
	elements_count = int(sys.argv[2])
	seed = sys.argv[3]
	
	obj = Solution()
	ret = obj.pa2_mergesort(input_type, elements_count, seed)
	print(ret)

