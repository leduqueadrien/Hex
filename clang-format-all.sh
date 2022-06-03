
# find . -name "*.cpp" -o -name "*hpp" | xargs -I {} echo {}
find . -name "*.cpp" -o -name "*hpp" | xargs -I {} clang-format -verbose -style=file -i {}
