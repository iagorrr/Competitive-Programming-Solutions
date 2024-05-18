all: update-readme

update-readme:
	python scripts/gen-readme/main.py > README.md