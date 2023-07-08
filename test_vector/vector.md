# string与vector的区别

1.vector<char>能不能替代string？
答案：不能——为啥？(1)因为vector对char字符不处理\0需要人为自动处理！(2)string比vector的接口更加丰富！

```c++
vector<char> strv;
string v;
```