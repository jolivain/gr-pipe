//
// Compile with: rustc -W warnings -O -o square-rust square-rust.rs
//

use std::io;
use std::io::Read;
use std::io::Write;

fn main() -> io::Result<()> {
    let mut buffer = [0; 4];

    loop {
        let n = io::stdin().read(&mut buffer[..])?;
        if n == 0 {
            break;
        }

        if n != 4 {
            eprintln!("Incomplete read. Skipping...");
            continue;
        }

        let val = f32::from_ne_bytes(buffer);

        let res = val * val;

        // println!("{:?}", res);

        io::stdout().write( &res.to_ne_bytes() )?;
    }

    Ok(())
}
