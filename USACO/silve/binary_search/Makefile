# Trình biên dịch
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2 


# Danh sách các chương trình cần build (bạn có thể thêm vào đây)
PROGRAMS = angry convention test cowdance socdist factory_machine array_division

# Quy tắc mặc định khi gõ "make" (sẽ build tất cả)
all: $(PROGRAMS)

# Quy tắc chung: build a từ a.cpp, b từ b.cpp, v.v.
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Quy tắc dọn dẹp
clean:
	rm -f $(PROGRAMS)

clean-%:
	rm -f $*

run-%: %
	ulimit -s unlimited && ./$<
