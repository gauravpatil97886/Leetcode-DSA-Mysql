var bound = [][]int{
	{10, 98},
	{1_000, 9988},
	{100_000, 999_888},
	{10_000_000, 99_998_888},
}

func numberOfBeautifulIntegers(low int, high int, k int) int {
	if low > high || k > high || k == 0 || high < 9 {
		return 0
	}

	var l, h, res int

	for _, b := range bound {
		if low > b[1] || high < b[0] {
			continue
		}
		l, h = max(low, b[0]), min(high, b[1])

		if l%k != 0 {
			l = l - (l % k) + k
		}

		res += check(l, h, k)
	}

	return res
}

func check(low, high, k int) int {
	var res, e, i int
	d := numDigits(low)

	for i = low; i <= high; i += k {
		e = oddDigits(i)
		if d-e == e {
			res++
		}
	}

	return res
}

func oddDigits(n int) int {
	r := 0
	for n > 0 {
		r += n & 1
		n /= 10
	}
	return r
}

func numDigits(n int) int {
	r := 0
	for n > 0 {
		r++
		n /= 10
	}
	return r
}

func min(x, y int) int {
	if x <= y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x >= y {
		return x
	}
	return y
}