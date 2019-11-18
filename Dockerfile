FROM g++:latest
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -std=c++2a -fconcepts main.cpp -o concept
CMD ["./concept"]