# SUDOKU CLASSIC VERSION


- Thử nghiệm game :


# Giới thiệu game 

Sudoku là 1 tựa game đơn giản, phổ biến với đại đa số mọi người trên toàn thế giới. Người chơi có nhiệm vụ điền vào
các ô trống các chữ số từ 1-9  sao cho mỗi hàng, mỗi cột và mỗi cặp ô 3x3 không có bất kì số nào trùng nhau. Vì là 
game giải đố nên game giúp người chơi tăng tính tư duy logic cho người chơi, giúp tăng khả năng fix bug khi gặp vấn 
đề.

# Cấu trúc game

Cấu trúc của game gồm có 2 phần chính:

- Bảng game Sudoku
- Các phần tử trong bảng
- ## Bảng game Sudoku
- Thiết kế bằng SDL, màu lấy từ file ảnh: <img src="res/images/bg.png" width=50> , <img src="res/images/blank.png" width=50>
- Nút restart : <img src="res/images/restart.png" width=50>

# Các Phần tử trong bảng
|  Phần tử | Ảnh|
|-----------------|---------------|
|Số 1 hợp lệ | <img src="res/images/number1.png" width=50>|
|Số 2 hợp lệ | <img src="res/images/number2.png" width=50>|
|Số 3 hợp lệ | <img src="res/images/number3.png" width=50>|
|Số 4 hợp lệ | <img src="res/images/number4.png" width=50>|
|Số 5 hợp lệ | <img src="res/images/number5.png" width=50>|
|Số 6 hợp lệ | <img src="res/images/number6.png" width=50>|
|Số 7 hợp lệ | <img src="res/images/number7.png" width=50>|
|Số 8 hợp lệ | <img src="res/images/number8.png" width=50>|
|Số 9 hợp lệ | <img src="res/images/number9.png" width=50>|
|Số 1 ko hợp lệ | <img src="res/images/false1.png" width=50>|
|Số 2 ko hợp lệ | <img src="res/images/false2.png" width=50>|
|Số 3 ko hợp lệ | <img src="res/images/false3.png" width=50>|
|Số 4 ko hợp lệ | <img src="res/images/false4.png" width=50>|
|Số 5 ko hợp lệ | <img src="res/images/false5.png" width=50>|
|Số 6 ko hợp lệ | <img src="res/images/false6.png" width=50>|
|Số 7 ko hợp lệ | <img src="res/images/false7.png" width=50>|
|Số 8 ko hợp lệ | <img src="res/images/false8.png" width=50>|
|Số 9 ko hợp lệ | <img src="res/images/false9.png" width=50>|

# Chức năng game 
- Máy sẽ random ra màn hình 1 bảng game Sudoku ngầu nhiên chưa hoàn chỉnh.
- Người chơi sẽ điền các giá trị từ 1-9 vào các ô trống; nếu giá trị sai thì hiện màu đỏ, đúng thì hiện màu đen
- Người chơi hoàn thành khi toàn bộ các ô đều hoàn thành.
- Nhấn nút restart để tạo bảng game Sudoku mới.
  # Mã nguồn
  |           File nguồn    |Chức năng|
  |--------------------------|---------|
  |main.cpp|  |
  |board.cpp|  |
  |entity.cpp| |
  |render_window.cpp|  |
  |mouse.cpp|  |
  |math.cpp|  |
  |square.cpp|  |
  # Nguồn tham khảo
- CoderGopher: https://www.youtube.com/@codergopher8270
- Nhóm Phát Triển Phần Mềm: https://phattrienphanmem123az.com/lap-trinh-game-c-p2
- ChatGPT, Blackbox AI.



