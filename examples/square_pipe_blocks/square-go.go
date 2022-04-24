//
// Run with: go run square-go.go
// or
// Compile with: go build square-go.go
// Execute with: ./square-go
//

package main

import (
  "bufio"
  "fmt"
  "os"
  "io"
  "bytes"
  "encoding/binary"
)

func main() {

    reader := bufio.NewReader(os.Stdin)

    buf := make([]byte, 4)
    buf_reader := bytes.NewReader(buf)
    var val float32

    for {
        n, err := reader.Read(buf)
        if err == io.EOF {
            break
        }
        if n != 4 {
            fmt.Fprintf(os.Stderr, "Incomplete read. Skipping...\n")
            continue
        }

        buf_reader.Reset(buf)

        err2 := binary.Read(buf_reader, binary.LittleEndian, &val)
        if err2 != nil {
            fmt.Println("binary.Read failed:", err2)
            continue
        }

        //fmt.Fprintf(os.Stderr, "%f\n", val)
        var res = val * val

        err3 := binary.Write(os.Stdout, binary.LittleEndian, res)
        if err3 != nil {
            fmt.Println("binary.Write failed:", err3)
        }
    }
}
