a, b, c, d  = map(int, input().split())
tmp = a
a = b
b = tmp

tmp = c
c = d
d = tmp

h 		= c - a

odd_lines  	= h//2
even_lines 	= h//2

if h % 2 != 0:
	if abs(a) % 2 == 0:
		even_lines += 1
	else:
		odd_lines += 1

ans = 0

even_v	= [ 2, 1, 0, 1 ]
odd_v	= [ 1, 2, 1, 0 ]

w = d - b
for i in range(b, d):
	if i % 4 == 0:
		full_w = w // 4
		full_even = even_lines * sum(even_v) * full_w
		full_odd = odd_lines * sum(odd_v) * full_w
		
		ans += full_even + full_odd
		for j in range(0, (w % 4)):

			even_i = even_lines * even_v[j]
			odd_i = odd_lines * odd_v[j]

			ans += even_i + odd_i


		break

	even_i = even_lines * even_v[i%4]
	odd_i = odd_lines * odd_v[i%4]

	ans += even_i + odd_i
	w -= 1

print(ans)

