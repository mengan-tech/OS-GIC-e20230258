# Lab 3 — Wildcards, Hard Links and Symbolic Links

- **Student name/ID:** HAN MENGAN/e20230258
- **Ubuntu username:** gic-han-mengan
- **My values (`oslab values lab3`):** name = tiger, tag = backup, v1 = 843, v2 = 892
- **Files:** `evidence/wildcards.txt`, `evidence/links.txt`, `evidence/replacement.txt`, `evidence/checkpoint.txt`

## What I Saw

| State | What `cat` printed for the hard link | What `cat` printed for the symbolic link | What `readlink` printed |
|---|---|---|---|
| Before the rename | version 843 | version 843 | tiger.txt |
| After the rename, before the repair | version 843 | Error: No such file or directory | tiger.txt |
| After a new file took the old name | version 843 | version 892 | tiger.txt |
| After my repair | version 843 | version 843 | [Actual repaired target] |

**My repair (the two commands I wrote):**

```bash
rm -- tiger-soft.txt
ln -s tiger-backup.txt tiger-soft.txt
```

## Explanation

The hard link and symbolic link behave differently because they store different types of references. A hard link points directly to the same inode as the original file, so it continues to read the original data, which is version 843. A symbolic link stores a pathname instead of pointing directly to the inode. When the original file was renamed and a new `tiger.txt` was created with version 892, the symbolic link followed the old pathname and read the new file. This explains why the hard link still printed version 843 while the symbolic link printed version 892.

## What My Tests Do Not Prove

The `cat` command only shows the file content; it does not prove whether two filenames refer to the same inode. The `ls -li` command shows inode numbers and helps us verify whether files share the same inode.

## Plus
In this exercise, I tested wildcard patterns using square brackets.

[12] matches exactly one character, either 1 or 2.

[!1]* matches a filename beginning with any character except 1, followed by any number of characters.

These patterns helped me understand how Linux wildcards can match specific characters or exclude certain characters when searching for filenames.

## Challenge
In this challenge, I created one file and gave it three different filenames using hard links.

mkdir -p extra
cd extra

printf 'keep me\n' > one.txt
ln one.txt two.txt
ln one.txt three.txt

ls -l one.txt two.txt three.txt

## AI Note (optional)

I used an AI tool to understand the difference between hard links and symbolic links. I checked its explanation by creating links, renaming files, and comparing their contents and inode numbers using Linux commands.

