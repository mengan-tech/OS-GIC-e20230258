# Lab 2 — Linux Navigation and File Management: individual report

Copy this template to `lab2/README.md` in your own course repository. Follow [the instructions](lab2-instruction.md). Your prediction, debrief and checkpoint answers are already saved by `oslab`; do not copy them here. The marks come from those records and your evidence files; this report is your own record of the lab.

- Student name/ID: HAN MENGAN / e20230258
- Ubuntu username: gic-han-mengan
- My values (`oslab values lab2`): file1 = 'cash flow.txt', file2 = 'payroll may.txt' , owner = Audit , reader = HR , third = Support
- Files: `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`, `evidence/challenge.txt`, `evidence/plus.txt`

## What I Did

| Step | Step | My command | Current folder when I ran it |
|---|---|---|
| Move the first file (relative destination) | `mv -- "$file1" ../reports/` | `lab2/incoming` |
| Move the second file (absolute paths) | `mv -- "$OSLAB_WORKSPACE/lab2/incoming/$file2" "$OSLAB_WORKSPACE/lab2/reports/"` | `lab2` |
| Read the report from my reader department (relative path) | `cat ../"$owner/$file1"` | `lab2/TechCorp/HR` |
| The path error I made on purpose, and its message | `cat "reports/$file1"` → `cat: 'reports/cash flow.txt': No such file or directory` | `lab2/TechCorp/HR` |
| The relative path that fixed it | `cat "../../reports/$file1"` | `lab2/TechCorp/HR` | My command | Current folder when I ran it |


## Explanation

`oslab debrief lab2` records which prediction answers you confirmed and which you corrected. Here, in 3–5 sentences for yourself: why can a correct file name still give "No such file or directory"? What is the difference between `mv` and `cp`, using your own files as the example?

- A correct file name can still give "No such file or directory" because a relative path
starts from the current folder. From `TechCorp/HR`, `reports/cash flow.txt` means
`TechCorp/HR/reports/cash flow.txt`, which does not exist; the real file is in
`lab2/reports/`, so I needed `../../reports/cash flow.txt` (or an absolute path).
`mv` moves a file: after `mv 'incoming/cash flow.txt' reports/` there was still only
one `cash flow.txt`, and `incoming/` no longer had it. `cp` makes a copy: after
`cp 'reports/cash flow.txt' TechCorp/Audit/` there were two, and the original stayed
in `reports/`.

## What My Tests Do Not Prove

One or two sentences. Think about what `ls` shows and what `cmp` shows.
- ls show the files name and the file name not prove it. cmp: compare both file by bytes if they match, they are the same.
## Plus / Challenge (only if you did them)

Your one-command move and the number of `..`, or your wildcard answers.
**Plus:** From inside `mess/c`, I moved and renamed the file with one command:
`mv -- "../a/b/lost file.txt" found.txt`. From inside `mess/a/b`, I copied it with
`cp -- ../../c/found.txt "../../../TechCorp/$third/"`. I needed 3 `..` to get from
`mess/a/b` up to the lab folder (b → a → mess → lab2), then down into `TechCorp/Support/`.

**Challenge:** I used `cp -- reports/*.txt "TechCorp/$third/"`. With quotes,
`"*.txt"` fails because the shell does not expand the `*`, so `cp` looks for a file
literally named `*.txt`. `reports/.hidden.txt` is not copied because `*` does not
match names that start with `.` (hidden files).

## AI Note (optional)

One suggestion an AI tool gave you and the test you used to check it.
