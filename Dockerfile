FROM ubuntu:latest

RUN mkdir test

COPY . /test

WORKDIR /test

RUN export DISPLAY=1 

RUN apt update -y

RUN apt-get install libsfml-dev -y

RUN apt install clang -y && apt install g++ -y

RUN apt install make -y

RUN make

CMD [ "./ChessGame" ]