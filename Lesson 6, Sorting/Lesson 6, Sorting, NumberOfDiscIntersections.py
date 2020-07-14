def solution(A):
	range_circ = [list()] * len(A)
	for i in range(len(A)):
		range_circ[i] = [i - A[i], i + A[i]]
		#print(f"{range_circ[i][0]} -> {range_circ[i][1]}")

	range_circ.sort()

	intersecting = 0
	for i in range(len(A)-1):
		for j in range(i+1, len(A)):
			if (range_circ[i][0] >= range_circ[j][0] and range_circ[i][0] <= range_circ[j][1]) \
				or (range_circ[i][1] <= range_circ[j][1] and range_circ[i][1] >= range_circ[j][0]) \
				or (range_circ[j][0] >= range_circ[i][0] and range_circ[j][0] <= range_circ[i][1]) \
				or (range_circ[j][1] <= range_circ[i][1] and range_circ[j][1] >= range_circ[i][0]):
				intersecting += 1
				#print(f"i = {i}, j = {j}, intersecting = {intersecting}")
				if intersecting > 10e6:
					return -1
		
	return intersecting





def solution(A):
	from_, to = [None] * len(A), [None] * len(A)
	for i in range(len(A)):
		from_[i] = i - A[i]
		to[i] = i + A[i]
		#print(f"{from_[i]} -> {to[i]}")

	intersecting = 0
	for i in range(len(A)-1):
		for j in range(i+1, len(A)):
			if (from_[i] >= from_[j] and from_[i] <= to[j]) \
				or (to[i] <= to[j] and to[i] >= from_[j]) \
				or (from_[j] >= from_[i] and from_[j] <= to[i]) \
				or (to[j] <= to[i] and to[j] >= from_[i]):
				intersecting += 1
				#print(f"i = {i}, j = {j}, intersecting = {intersecting}")
				if intersecting > 10e6:
					return -1
		
	return intersecting
