#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval(double total = 0) const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval(double) const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval(double) const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	Mean() : m_mean{} {
	}

	void update(double next) override {
		m_mean += next;
	}

	double eval(double total = 1) const override {
		return m_mean/total;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double m_mean{};
};

using namespace std;

class Std : public IStatistics {
public:
	Std() : m_std{} {
	}

	void update(double next) override {
		m_std += next;
        tmp.push_back(next);
	}

	double eval(double total = 1) const override {
        double m = m_std/total;
        double d{};
        for(auto it = tmp.begin(); it != tmp.end(); ++it) {
            d = d + pow((*it - m),2);
        }

		return sqrt(d/total);
	}

	const char * name() const override {
		return "std";
	}

private:
	double m_std{};
    vector<double> tmp{};
};

int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	double val = 0;
	double total = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
        ++total;
	}
	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval(total) << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}
