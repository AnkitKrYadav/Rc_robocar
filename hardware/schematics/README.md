# Circuit Schematics

This directory contains circuit schematics and PCB design files for the RC Robocar project.

## File Types

### Schematic Files
- `rc_robocar_schematic.sch` - Main circuit schematic (KiCad/Eagle format)
- `rc_robocar_schematic.pdf` - PDF version for easy viewing
- `rc_robocar_breadboard.fzz` - Fritzing breadboard layout

### PCB Design Files
- `rc_robocar_pcb.kicad_pcb` - PCB layout (KiCad format)
- `rc_robocar_pcb.brd` - PCB layout (Eagle format)
- `gerber_files/` - Gerber files for PCB manufacturing

### Bill of Materials
- `bom.csv` - Complete component list with part numbers
- `bom.xlsx` - Formatted BOM with supplier information

## Design Software

### Recommended Tools
1. **KiCad** (Free, open-source)
   - Professional PCB design
   - Large component library
   - 3D visualization

2. **Fritzing** (Free for basic use)
   - Beginner-friendly
   - Breadboard view
   - Educational focus

3. **Eagle** (Paid, free for small projects)
   - Industry standard
   - Extensive libraries
   - Professional features

### File Formats
- `.sch` - Schematic files
- `.pcb`, `.brd` - PCB layout files
- `.pdf` - Universal viewing format
- `.gerber` - Manufacturing files
- `.csv/.xlsx` - Bill of materials

## Design Guidelines

### Schematic Standards
- Use standard symbols and conventions
- Clear component labeling
- Logical signal flow (left to right)
- Proper power and ground symbols
- Include component values

### PCB Design Rules
- Minimum trace width: 0.3mm (12 mil)
- Power traces: 1.0mm+ (40 mil+)
- Via size: 0.6mm (24 mil)
- Component spacing: Allow for hand soldering
- Ground plane for noise reduction

## Contributing Schematics

### Submission Requirements
1. Source files in native format
2. PDF export for viewing
3. Component library files if custom parts used
4. Design rule check (DRC) passed
5. Bill of materials included

### Review Checklist
- [ ] Electrical correctness verified
- [ ] Component footprints correct
- [ ] Manufacturability considered
- [ ] Cost optimization evaluated
- [ ] Documentation complete

## Manufacturing Information

### PCB Specifications
- **Board Thickness**: 1.6mm standard
- **Copper Weight**: 1oz (35μm)
- **Surface Finish**: HASL or ENIG
- **Solder Mask**: Green standard
- **Silkscreen**: White on top side

### Assembly Options
- **Hand Assembly**: Components selected for hand soldering
- **Professional Assembly**: Provide pick-and-place files
- **Mixed Assembly**: SMD professionally, through-hole by hand

## Version Control

### File Naming
```
rc_robocar_schematic_v1.0.sch
rc_robocar_pcb_v1.0.kicad_pcb
bom_v1.0.csv
```

### Version History
- v1.0 - Initial design with basic functionality
- v1.1 - Added protection circuits
- v2.0 - Optimized layout for competition use

---

*Note: Actual schematic files will be added as the project develops. Start with breadboard prototyping before moving to PCB design.*