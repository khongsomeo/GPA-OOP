FROM gcc:12.4.0

COPY . /gpa-oop

WORKDIR /gpa-oop

RUN make

ENTRYPOINT [ "./main" ]
