from pathlib import Path
import argparse

def _get_intro() -> str:
    INTRO_PATH = Path(__file__).parent.absolute() / '100-intro.md'
    with open(INTRO_PATH) as f:
        md = f.read()
    return  md

def _get_bullet_link(entry_path: Path) -> str:
	entry_path = entry_path.absolute().__str__()
	i = entry_path.find("/submissions")
	link = entry_path[i:]
	link = link.replace(" ", "%20")
	return link
		
def _build_bullet(entry_path: Path, ident: int):
	TAB_SIZE: int = 4
	name = entry_path.name
	link = _get_bullet_link(entry_path=entry_path)
	bullet:str = ident*TAB_SIZE*" " + f" - [{name}]({link})\n"
	return bullet


TO_EXPAND: set[str] = set(["ICPC", "Maratonas DF"])
def _get_folder_bullets(sub_path: Path, depth: int) -> str:
	md = ""
	
	for folder in sub_path.iterdir():
		if not folder.is_dir():
			continue

		md += _build_bullet(folder, depth)
		
		if folder.name in TO_EXPAND:
			md += _get_folder_bullets(folder, depth + 1)

	return md

def _get_submissions_md(sub_path: Path) -> str:
	md = "## Submissions\n\n"

	md += _get_folder_bullets(sub_path, 0)
	
	return md


def _build_md(sub_folder: Path) -> str:
	md = _get_intro()
	md += _get_submissions_md(sub_path=sub_folder)
	return md



def _save_output(md: str, out_path: Path) -> None:
	with open(out_path, 'w') as f:
		f.write(md)
	


def _set_arguments() -> argparse.Namespace:
    DEFAULT_OUTPUT_PATH: Path = Path().parent.parent.parent / "README.md"
    DEFAULT_SUBMISSIONS_FOLDER: Path = Path().parent.parent.parent / "submissions"
    parser = argparse.ArgumentParser(
        prog="Create read script",
        description="Create a pretty README that links the submission folder"
    )
    parser.add_argument(
        "-o", "--output", default=DEFAULT_OUTPUT_PATH,
        help="specify the path to where the README should be stored"
    )

    parser.add_argument(
        "-s",
        "--submissions",
        default=DEFAULT_SUBMISSIONS_FOLDER,
        help="specify the path to the submissions folder"
    )
    args = parser.parse_args()
    return args

if __name__ == "__main__":
	args: argparse.Namespace = _set_arguments()
	md: str = _build_md(sub_folder=args.submissions)
	_save_output(md=md, out_path=args.output)
