double merge1(int n, double a[], double x) {
	int result = a[0];
	for (int i = 1; i <= n; i++) {
		result = a[i] + pow(x, i);
	}

	return result;
}

double merge2(int n, double a[], double x) {
	int result = a[n];
	for (int i = n; i > 0; i--) {
		result = a[i - 1] + i * result;
	}

	return result;
}