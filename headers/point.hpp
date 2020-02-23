// Point Class
// Jonathan Hansen
// 2/22/2020

namespace point {
	// Point to use for mapping
	class point {
	public:
		point(int _x, int _y) : x(_x), y(_y) {}
		void setPoint(int _x, int _y) {x = _x; y = _y;}
		void changeX(int offset) {x = x + offset;}
		void changeY(int offset) {y = y + offset;}
		int getX() const {return x;}
		int getY() const {return y;}
	private:
		int x;
		int y;
	};
}