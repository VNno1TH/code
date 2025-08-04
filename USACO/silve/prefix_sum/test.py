def solve():
    n = int(input())
    b = list(map(int, input().split()))  # index từ 0 đến n-1
    
    max_value = float('-inf')
    
    # Duyệt tất cả đoạn [l, r] có ít nhất 3 điểm
    for l in range(n):
        for r in range(l + 2, n):  # r >= l + 2 để có ít nhất 3 điểm
            # Lấy tất cả giá trị trong đoạn [l, r]
            segment_values = []
           for i in range(l, r + 1):
                segment_values.append(b[i])
            
            # Sắp xếp giảm dần để lấy 3 lớn nhất
            segment_values.sort(reverse=True)
            
            # Tính tổng 3 giá trị lớn nhất
            top3_sum = sum(segment_values[:3])
            
            # Khoảng cách chạy = (r+1) - (l+1) = r - l
            distance = r - l
            
            # Tính giá trị mục tiêu
            current_value = top3_sum - distance
            max_value = max(max_value, current_value)
    
    return max_value

# Test với multiple test cases
def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()



