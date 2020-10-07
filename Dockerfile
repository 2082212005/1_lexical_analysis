FROM g++:latest
WORKDIR /app/
COPY ./* ./
RUN g++ main.cpp -o program
RUN chmod +x program