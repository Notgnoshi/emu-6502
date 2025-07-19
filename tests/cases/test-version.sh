./asm --version >test-version.out 2>&1
diff $EMU_REPO/tests/cases/test-version.txt test-version.out
