"""
	only works in the file structure of the repo :(
"""
from pathlib import Path
import argparse
import re
import os



def _set_arguments() -> argparse.Namespace:
    DEFAULT_OUTPUT_PATH: Path = Path().parent.parent.parent / "README.md"
    DEFAULT_SUBMISSIONS_FOLDER: Path = Path().parent.parent.parent / "submissions"
    parser = argparse.ArgumentParser(
        prog="Create read script",
        description="Create a pretty README that links the submission folder"
    )
    parser.add_argument(
        "-o", "--output", default=DEFAULT_OUTPUT_PATH,
        help="specify where the README should be stored"
    )

    parser.add_argument(
        "-s",
        "--submissions",
        default=DEFAULT_SUBMISSIONS_FOLDER,
        help="specify where the folder to the submissions"
    )
    args = parser.parse_args()
    return args

def _get_intro() -> str:
    INTRO_PATH = Path(__file__).parent.absolute() / '100-intro.md'
    with open(INTRO_PATH) as f:
        md = f.read()
    return  md

def _get_bullet_link(entry_path: Path) -> str:
	entry_path = entry_path.absolute().__str__()
	i = entry_path.find("/submissions")
	link = entry_path[i:]
	return link
		
def _build_bullet(name: str, link: str, ident: int):
	TAB_SIZE: int = 8
	bullet:str = ident*TAB_SIZE*" " + f" - [{name}]({link})\n"
	return bullet

def _get_submissions_md(sub_path: Path) -> str:
	TO_EXPAND: set[str] = set(["ICPC", "Maratonas DF", "Meta-hacker-Cup"])

	md = "## Submissions\n"
	
	for folder in sub_path.iterdir():
		if not folder.is_dir():
			continue

		link:str = _get_bullet_link(folder)
		name:str = folder.name
		md += _build_bullet(name, link, 0)



	return md


def _build_md(sub_folder: Path) -> str:
	md = _get_intro()
	md += _get_submissions_md(sub_path=sub_folder)
	return md



def _save_output(md: str, out_path: Path) -> None:
	with open(out_path, 'w') as f:
		f.write(md)
	


if __name__ == "__main__":
	args: argparse.Namespace = _set_arguments()
	md: str = _build_md(sub_folder=args.submissions)
	_save_output(md=md, out_path=args.output)
