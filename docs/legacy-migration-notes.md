# Legacy Migration Notes

This file summarizes what was reviewed from `Local_legacy` and how migration decisions were made.

## Reviewed Legacy Sources

- Duplicated project trees under `Local_legacy/code/` and `Local_legacy/demo/`
- Legacy personal/course documents (`.docx`, `.pdf`)
- Legacy helper/tutorial files and screenshots
- Prototype Python script `Local_legacy/cwk1d.py`

## Findings

- Core C source and tests in `Local_legacy/code/` are equivalent to current root project with no critical functional deltas for merge.
- Legacy folder includes many duplicated or environment-specific artifacts (`.vscode` logs/configs, generated binaries, zipped snapshots).
- Personal and institutional identifiers appear in legacy documents and old readme text.

## Migration Decision

- Keep root `src/`, `test/`, `unity/` as the primary maintained codebase.
- Remove `Local_legacy/` from the repository after extracting useful context and documents.
- Remove obvious duplicate/obsolete root metadata files and replace them with clean open-source docs.

## Privacy and Open-source Sanitization

- Removed old root metadata text file with personal repository reference.
- Replaced course-specific README content with neutral project documentation.
- Added open-source baseline files: license, contributing, security, conduct, multilingual docs.
