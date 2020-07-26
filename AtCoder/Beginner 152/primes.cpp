vector<bool> is_prime;
vi primes;
void create_primes(int maxN) {
	is_prime.assign(maxN + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= maxN; ++i) if (is_prime[i]) {
		primes.push_back(i);
		for (int j = i * i; j <= maxN; j += i) 
			is_prime[j] = false;
	}
}